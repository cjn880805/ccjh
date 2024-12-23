//dadieshui.h

//Sample for room: ����Ǵ��ˮ�ٲ�
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_dadieshui);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǵ��ˮ�ٲ�");

	add_npc("pub_youke");     // add by zdn 2001-07-12 

	add_door("�������Ϫ��̶", "�������Ϫ��̶", "����Ǵ��ˮ�ٲ�");
	add_door("����ǲ軨ɽ��", "����ǲ軨ɽ��", "����Ǵ��ˮ�ٲ�");
	add_door("�����ɽ��С��", "�����ɽ��С��", "����Ǵ��ˮ�ٲ�");

	set("long", "��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������ˮ���ĺ�������ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ޴�ĺ����������Ǵ����乵�ﴫ���ġ������ϵ�֮����С·���ٷ�ʯ��ǰ��" );
	
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
