//kedian.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_xiaoer2");   //zdn 2001-07-12 add

	add_npc("pub_baixiaosheng");
	CContainer * env = load_room("pk");
	if(env->query("�")==1)
		add_npc("wiz_109");
	else if(env->query("�")==2)
		add_npc("wiz_teacher2");

	add_door("�ɶ���", "�ɶ���", "�ɶ�������");
	add_door("�ɶ��������¥", "�ɶ��������¥", "�ɶ�������");

	set("long",	"��������ȫ�������Ŀ͵꣬����ǳ���¡������οͶ�ѡ��������ţ��������������������صķ������顣��С����������æ������ת�����صĴ�ζ�ٻ�����ʵ������˳�������ǳɶ������ٰ�Ŀ�ջ���Ӵ��Ÿ����봨�Ĺٲ����ˡ�ǽ�Ϲ���һ������(paizi)��"	);
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("sleep_room",1);


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




