//beidimiao.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRFoShan_beidimiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_xiaoer4");
	add_npc("pub_scavenger");
	add_npc("wiz_newbie001");
	add_item("caishen");
	add_item("guanyin");
	add_door("��ɽ", "��ɽ", "��ɽ������");
	add_door("���괺������", "���괺������", "��ɽ������");
	
	set("long", "�������������ϡ�Ժ����һ����ˮ��������ʯ��ʯ�ߣ���Ȼ�̾ᡣ�������ʯ����Ѫ����Ȼ�������������ڴ�����С� " );
	

	//begin--  added by Lanwood 2001-02-13 
	set("valid_startroom", 1);
	set("no_fight", 1);
	set("no_cast",  1);
	//end----
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
