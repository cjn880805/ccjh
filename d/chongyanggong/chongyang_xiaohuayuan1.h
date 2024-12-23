//xiaohuayuan1.h

//Sample for room:  ������С��԰1
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaohuayuan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С��԰1");
	
	add_npc("quanzhen_zhangyuan");

	add_door("������", "������", "������С��԰1");
	add_door("������С��԰2", "������С��԰2", "������С��԰1");

	set("long", "���������������С��԰��������Ʈ��һ���ʻ�����ζ��������ȥ�����ǽ�����ˡ������԰����ȴ��ȫ�����������϶�������ĵط���԰�м�����һ���Ӳݣ�Ҳ��ר�����˸���������");

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