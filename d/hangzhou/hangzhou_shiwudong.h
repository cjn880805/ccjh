//shiwudong.h

//Sample for room: ����ʯ�ݶ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shiwudong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ʯ�ݶ�");

	//add npcs into the room
////	add_npc("animal_xiezi");
        add_npc("pub_boy");               // add by zdn 2001-07-14

	add_door("��������¤", "��������¤", "����ʯ�ݶ�");
	add_door("������ʯ���18", "������ʯ���18", "����ʯ�ݶ�");

	set("long","ɽ·����ʯ�ݶ���ʯ�ݶ��������ж������������������ߴ�����ྻ�������Ͽ���խ��״�縡�ݡ����ϱ㵽������¤��ɽ·�ľ�ͷ����һ���ɱ����ϵĴ����" );
    

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
