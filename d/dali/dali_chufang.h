//chufang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	CBox * box = Add_Box();
	box->add_object("puercha", 1);	
	box->set_name( "����");	

	add_door("�������������", "�������������", "�������������");

	set("long", "������������������������������ʮ�ֿ�������˵��������������ܼ򵥣����м�������̫ʦ�Σ����ϰ����˸��ָ�����ɽ�軨��" );

};


ROOM_END;
