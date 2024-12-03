#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def enviar_comando():
    rospy.init_node('pubFuso', anonymous=True)
    pub = rospy.Publisher('comando_motor', String, queue_size=10)
    rate = rospy.Rate(1)  # 1 Hz

    while not rospy.is_shutdown():
        comando = "20|S"  # Exemplo: 57 voltas no sentido CW (subir)
        rospy.loginfo(f"Enviando comando: {comando}")
        pub.publish(comando)
        rate.sleep()

if __name__ == '__main__':
    try:
        enviar_comando()
    except rospy.ROSInterruptException:
        pass
