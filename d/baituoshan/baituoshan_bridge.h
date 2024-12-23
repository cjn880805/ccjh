//bridge.h

//Sample for room: ����ɽС��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_bridge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽС��");

	//add npcs into the room
	add_npc("pub_cungu");
	
	add_door("����ɽ����", "����ɽ����", "����ɽС��");
	add_door("����ɽ�㳡", "����ɽ�㳡", "����ɽС��");

	set("long", "����һ��С���ţ�������ɽ���ϵı�ѩ�ڻ��γ�һ���峺��СϪ�������»�����������ʱ����Ƥ��С��Ծ��ˮ�棬�������»���һ������ɫ�Ļ��ߡ�");
	
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
