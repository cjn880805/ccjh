//lingyunti.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_lingyunti);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("pub_girldizi");        //add by zdn 2001-07-14

	add_door("����ϴ���", "����ϴ���", "����������");
	add_door("�����׶�ƺ", "�����׶�ƺ", "����������");

	set("long","���������ݣ�������һλ�а��Ŷ����������ڴ˸�ľ��ʯ���Զ����ˣ��ֽС���ɮ�ݡ���·����÷���£��ɼ�������÷�綹������֦��Ҷ�ж������ˣ����С���÷ֹ�ʡ�֮���á����ݱ�ͨϴ��أ������׶�ƺ��");

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
