//xixiangchi.h

//Sample for room:  ����ϴ���
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_xixiangchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("pub_whitelady");      // add by zdn 2001-07-14
	add_npc("emei_girldizi");        //add by zdn 2001-07-20

	add_door("����������2", "����������2", "����ϴ���");
	add_door("����������", "����������", "����ϴ���");

	set("long","ϴ���ԭֻ��һͤ��ͤǰ��һ��ʯ����С��(pool)���ر߲�Զ����Σ�ҡ�ϴ���Ԣ��һƬ��ɼ���У��������������ɽ������������������̿������������ʱ�����������ţ�������ޣ����������칬�����������������������ġ���س�ҹ�����ɴ��������ʣ������׶�ƺ������������ʯ��");

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
