//zhuyuan.h

//Sample for room: ����ɽ��԰
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_zhuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��԰");

	add_door("����ɽ��԰", "����ɽ��԰", "����ɽ��԰");
	add_door("����ɽ��Է", "����ɽ��Է", "����ɽ��԰");
	add_door("����ɽ��Ժ", "����ɽ��Ժ", "����ɽ��԰");

	set("long", "������һ���ľ�����԰���߸ߵ͵͵Ĵ��������װ��ñ������¡��������Ǻ�Ժ���������и���Է���ϱ��ǻ�԰��.���������Ѹߣ����Ѿ����ɻ��ˣ������ﾲ��");
	
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
