//kedian.h

//Sample for room: ������͵�
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRhangzhou_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������͵�");

	//add npcs into the room
	add_npc("pub_xiaoer2");
	
	add_door("������ʯ���13", "������ʯ���13", "����������͵�");
	add_door("����������͵��¥", "����������͵��¥", "����������͵�");

	set("long","���Ǻ����������Ŀ͵꣬����������ڣ�װ�����繬��������������������صķ������顣��С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ�ǽ�Ϲ���һ������(paizi)��" );
	
	set("no_fight", 1);
    set("valid_startroom", 1);
    set("sleep_room",1);
	

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
