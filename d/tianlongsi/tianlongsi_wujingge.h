//wujingge.h

//Sample for room:  �������޾���
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_wujingge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������޾���");


	CBox * box = Add_Box();
	box->add_object("coin", 6000);	//put 100 coind into box
	box->set_name( "���");		//set box's name

				
	add_door("������������1", "������������1", "�������޾���");
	add_door("�����������", "�����������", "�������޾���");

	set("long","����������������ǰ�����㻹Ըʱ��Ϣ�ĵط�������̴��¯����齰�����һӦ��ȫ���徲֮����Ȼ͸��һ˿����֮��");

/******************************************************************************

******************************************************************************/
};


ROOM_END;
