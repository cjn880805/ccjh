//storeroom.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_storeroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");


	add_door("����ɽԺ��", "����ɽԺ��", "����ɽ������");

	set("long", "����һ�������ң������ܲ�͸�硣ֻ�йر��ŵĴ���(door)��");  
    
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
