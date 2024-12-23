//zhishuang.h

//Sample for room: ��ˬ��
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhishuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ˬ��");
	
	add_npc("pub_jianke");
	add_npc("pub_youke");        //add by zdn 2001-07-15


	add_door("����ǧ��ʯ", "����ǧ��ʯ", "������ˬ��");

	set("long", "��ǧ��ʯ���������ˬ�������������ڻ������������棬��ɽ�ϵ���ߵ㡣����ȡ����ɽˬ������Ϧ������֮�⡣�ɳơ�С��̨�����Ǻ�ӿ�嶥������ƽ̨�������Ұ��Զ��Ⱥ�����ƣ������������硰ʨ�ӻ�ͷ������һ�������＾�ڹ۳�Ⱥ����Ĳ�ӥ��εΪ׳�ۡ�" );
	
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
