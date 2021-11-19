#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

#include <QApplication>
#include <QTimer>
#include <QWidget>

int gst_camera(int argc, char *argv[])
{


    gst_init (&argc, &argv);
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(true);

    /* prepare the pipeline */

    GstElement *pipeline = gst_pipeline_new ("xvoverlay");
    GstElement *source = gst_element_factory_make ("v4l2src", NULL);
    GstElement *convert = gst_element_factory_make("videoconvert", NULL);
    //GstElement *zbar = gst_element_factory_make("zbar", NULL);
    GstElement *convert2 = gst_element_factory_make("videoconvert", NULL);
    GstElement *sink = gst_element_factory_make ("ximagesink", NULL);
    if (!pipeline || !source || !sink ||  !convert) {
       g_printerr ("Not all elements could be created.\n");
       return -1;
     }

    gst_bin_add_many (GST_BIN (pipeline), source, convert, /* zbar, convert2, */ sink, NULL);
    if(gst_element_link_many (source, convert, /* zbar, convert2,*/ sink, NULL) != TRUE) {
       g_printerr ("Elements could not be linked.\n");
       gst_object_unref (pipeline);
       return -1;
     }

    /* prepare the ui */

    QWidget window;
    window.resize(1280, 720);
    window.setWindowTitle("GstVideoOverlay Qt demo");
    window.show();

    WId xwinid = window.winId();
    gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (sink), xwinid);

    /* run the pipeline */

    GstStateChangeReturn sret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
    if (sret == GST_STATE_CHANGE_FAILURE) {
      gst_element_set_state (pipeline, GST_STATE_NULL);
      gst_object_unref (pipeline);
      /* Exit application */
      QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
      return -1;
    }

    /* Wait error and QR decoding */
    GstBus *bus = gst_element_get_bus (pipeline);
    gboolean terminate = FALSE;

    do {
      GstMessage *msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

      /* Parse message */
      if (msg != NULL) {
        switch (GST_MESSAGE_TYPE (msg)) {
          case GST_MESSAGE_ERROR:
            GError *err;
            gchar *debug_info;
            gst_message_parse_error (msg, &err, &debug_info);
            g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), err->message);
            g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
            g_clear_error (&err);
            g_free (debug_info);
            terminate = TRUE;
            break;
          case GST_MESSAGE_ELEMENT:
            if(g_strcmp0(GST_MESSAGE_SRC_NAME(msg), "zbar") == 0)   {
                g_print("Data : ? \n");
                //g_print("Data : %s \n", gst_structure_get_string(gst_message_get_structure(msg), "symbol"));
            }
            break;
          default:
            /* We should not reach here because we only asked for ERRORs and EOS */
            g_printerr ("Unexpected message received.\n");
            terminate = TRUE;
            break;
        }
        gst_message_unref (msg);
      }
    } while(!terminate);




    int ret = app.exec();

    window.hide();
    gst_object_unref(bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);


    return ret;
}
