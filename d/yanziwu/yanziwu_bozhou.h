//bozhou.h

//Sample for room: �����벴����
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_bozhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����벴����");

	add_door("������̫��", "������̫��", "�����벴����");
	add_door("������Ʒ��ͥ", "������Ʒ��ͥ", "�����벴����");

    set("long", "һƬ«έ�����״����ֳ�һ�����룬��С��ֻ�����ſ����⻨��Ҷ��������ˮ����ͨ�˴�ɴ˿ɳ˴��뿪�����롣������ϵ��һβС��(zhou)��" );
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