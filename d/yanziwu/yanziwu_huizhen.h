//huizhen.h

//Sample for room: ���������԰
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_huizhen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������԰");
	
	add_npc("murong_yan");        //add by zdn 2001-07-20

	add_door("�����볤��", "�����볤��", "���������԰");

    set("long", "���������������Ļ�԰����ֲ���ϵ��滨��ݣ�����Ũ����һȺ�ʵ��ڻ������ѷ��裬�㲻�ɵĳ��ˣ��е��ֶ�������" );
    
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