//changhu.h

//Sample for room: ����ǳ���
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_changhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǳ���");

	add_npc("pub_flowerg");         //add by zdn 2001-07-13

	add_door("�����֥�ƶ�", "�����֥�ƶ�", "����ǳ���");
	add_door("�����·��ʯ��", "�����·��ʯ��", "����ǳ���");
	add_door("����Ǻ�Ħ��ʯ��", "����Ǻ�Ħ��ʯ��", "����ǳ���");
	add_door("�����������ʯ��", "�����������ʯ��", "����ǳ���");

	set("long", "�������ܳ�Լʮ�������������Σ������������ܵĴ����С�������һ�����£��������л�ҫ�������ɰس��֣��Դ����Σ��������£�ɫ��Ҷ�ۣ�����ɽ������׺��䡣��ˮ���̣���һ����΢���ж����Ľ��У��̵ľ�Ө���̵Ļ�Ծ���̵����ˡ�");
	
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
