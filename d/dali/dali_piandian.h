//piandian.h

//Sample for room: ƫ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_piandian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ƫ��");

	add_npc("pub_shinu1");  //zdn 2001-07-12 add

	add_door("����ǻʹ�ǰ��", "����ǻʹ�ǰ��", "����ǻʹ�ƫ��");

	set("long", "�����Ǵ�����ʹ���ƫ�����ʵ۳�������Ӽ��ĸ��󳼣��������Եÿտյ����ģ������ǳ��ȡ�" );

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
