//jldongkou.h

//Sample for room:  ���Ҿ��϶���
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_jldongkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҿ��϶���");
	
	add_npc("pub_guest");            // add by zdn 2001-07-14
				
	add_door("��������ʯ", "��������ʯ", "���Ҿ��϶���");
	add_door("���Ҿ�ʮ�ŵ���4", "���Ҿ�ʮ�ŵ���4", "���Ҿ��϶���");

	set("long","���϶����ɷ����⡣��˵Զ��ʱ���о�λ����ס����������֪�������ں��꣬���ں��ꡣ��ԯ�ʵ۷õ��ڴˣ���һ���ţ���Ի�������º�������Ի�������ˡ�������Ǿ��϶������������������������˽�ȥ��ֻ��Щ��վ�ڶ���̸Ц���У�yell����������������ʮ�ŵ��յ�ǧ���֣�һ·�򱱵�����ʯ��");


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
