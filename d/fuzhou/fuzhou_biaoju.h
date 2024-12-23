//biaoju.h

//Sample for room: �����ھ�
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_biaoju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ھ�");

	add_npc("pub_biaotou");   // add by zdn 2001-07-13

	add_door("������", "������", "���ݸ����ھ�");
	add_door("���ݸ����ھ�����", "���ݸ����ھ�����", "���ݸ����ھ�");

    set("long", "��������ϲ豭��С��ͭ���������⣬�Ŷ��Ҷ�д�š������ھ֡��ĸ�������֣�������顰�ܺš�����С�֡����Ŵ����ų��ʣ�����������װ���ӣ����������ͦ���Գ�һ��Ӣ��֮����" );

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




