//chanfang.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_chanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("quanzhen_zhangli");

	CBox * box = Add_Box();
	box->add_object("gangjian");	
	box->set_name( "����");
	
	box->add_object("gangdao");				
	box->add_object("tiejiang");	
	
	add_door("������������", "������������", "����������");

	set("long", "������ȫ��̵��Ӱڷű������������������ҵض���һЩ�����е��Ѿ����ư߰��ˣ��еĻ��Ƿ���͸����ȫ�����������ʱ�򣬾͵���������ѡ���С�");

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
//last, register the room into ../server/RoomSetup.cpp