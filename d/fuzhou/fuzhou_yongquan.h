//yongquan.h

//Sample for room: ӿȪ��
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_yongquan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ӿȪ��");

	add_npc("pub_jianke");  //add by zdn 2001-07-13

	add_door("���ݶ�", "���ݶ�", "����ӿȪ��");

	set("long", "ӿȪ��Ϊ���е�һ���֡�������ΰ�����ư��磬���վ��ɣ��ھ�һʱ���¶�ʤ����Դ��������ͱڣ�������ɣ��������죬�������ţ�����ǧ�ر��֣������䡢������ī���±������壬Զ�������̲��������������������ƽԭһ����԰��⾡���۵ס�" );
	
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
