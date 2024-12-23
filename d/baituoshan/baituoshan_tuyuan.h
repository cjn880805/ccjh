//tuyuan.h

//Sample for room: ��Է
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_tuyuan);

virtual void create()			//Call it when Room Create
{
	set_name( "��Է");

	set("monster_chance", 1);
//	add_npc("animal_baitu");/////////////////////////
//	add_npc("animal_baitu");

	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ��Է");
	add_door("����ɽ����", "����ɽ����", "����ɽ��Է");
	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ��Է");

	set("long", "���Ǹ��������Է����ֻ����þ����ض����̲ݵ��ϳԲݡ������Ǻ��ţ����Ϸ�����԰�����洫���������޵ĺ��У�������һ����԰��");  

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
