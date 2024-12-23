//yunufeng.h

//Sample for room:  ������Ů��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_yunufeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������Ů��");

	add_npc("emei_fang");
		
	add_door("���ҹ��Ƹ�", "���ҹ��Ƹ�", "������Ů��");

	set("long","���ǹ��Ƹ�ߵ���Ů�壬�嶥��һ���ĳ߼�����С�أ������ĳߣ��ļ����ݣ���Ϊ��Ů��ԡ֮������ʱ�ݴ�ʷ��鮣����ڴ˽�é���ӣ������ж������Ͼ�������ʳ�˼��̻�������Ů�·���Ϊ������ʳ�");

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
