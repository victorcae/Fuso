#!/usr/bin/env python3
import rospy
from std_msgs.msg import Int32

def callback_voltas(data):
    rospy.loginfo(f"Voltas executadas pelo motor: {data.data}")

def monitorar_voltas():
    rospy.init_node('subFuso', anonymous=True)
    rospy.Subscriber('voltas_executadas', Int32, callback_voltas)
    rospy.spin()

if __name__ == '__main__':
    try:
        monitorar_voltas()
    except rospy.ROSInterruptException:
        pass
