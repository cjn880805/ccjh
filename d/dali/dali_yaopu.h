//yaopu.h

//Sample for room: ҩ��
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ҩ��");
	
	add_npc("pub_hehongyao");
	add_npc("pub_huoji");


	add_door("����Ƕ�", "����Ƕ�", "�����ҩ��");

	set("long", "����һ�����ص�ҩ�̣������ڴ�ͽֺ������ĵĽ��紦����ͨ����������ƣ��ַ��Ƕ�˵���ҩ�̵�ҩ����ĺܡ���ҩ���ϵļ��ٸ�С������ɢ��������һ��ŨŨ��ҩζ�����㼸����Ϣ����˵��ҵ�����һ�ֺ����ܵ�ҩ�" );

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
