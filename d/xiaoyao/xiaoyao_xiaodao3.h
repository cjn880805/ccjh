//xiaodao3.h

//Sample for room: С��3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaodao3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң��С��3");


	add_door("��ң��С��2", "��ң��С��2", "��ң��С��3");
	add_door("��ң�ִ�����", "��ң�ִ�����", "��ң��С��3");
	add_door("��ң�־Ƽ�", "��ң�־Ƽ�", "��ң��С��3");
	add_door("��ң��С��", "��ң��С��", "��ң��С��3");


};


ROOM_END;
