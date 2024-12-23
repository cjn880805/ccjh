//xiaoyao.h

//Sample for room  ��ң��
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXiaoYaocity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң��");


	add_door("��ң������", "��ң������", "��ң��");

	add_door("ľ��", "��ң��ľ��", "��ң��");
	add_door("ʯ��", "��ң��ʯ��", "��ң��");
	add_door("�Ƽ�", "��ң�־Ƽ�", "��ң��");
	add_door("С��", "��ң��С��", "��ң��");
	add_door("Сľ��", "��ң��Сľ��", "��ң��");
	add_door("������", "��ң�ִ�����", "��ң��");
	add_door("������", "��ң�ֹ�����", "��ң��");

};


ROOM_END;
