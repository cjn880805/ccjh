//zhufeng.h

//Sample for room: ����ɽ����
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_zhufeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����");

	add_npc("pub_youke");   // add by zdn 2001-07-13

	add_door("��Ĺɽ·", "��Ĺɽ·", "��Ĺ����ɽ����");
	add_door("����ɽɽ·4", "����ɽɽ·4", "��Ĺ����ɽ����");

	set("long","��ʱ������������ɽ���壬��Ұ��Ϊ������������ȥ��Ⱥɽ���������ڽ��¡��������Ĵ���������ɽ��������Ө���ԡ�ֻ�����ٵ���ɢ���ɽ��䣬��ɫ��Ϊ���һ���ʯ (shi)����һ�ԣ��ƺ�����ʲ�ᶫ�����������ϸ���һ��ɽ·��");
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
