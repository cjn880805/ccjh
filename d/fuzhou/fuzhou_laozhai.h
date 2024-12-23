//laozhai.h

//Sample for room: ������լ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_laozhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������լ");

	add_npc("pub_boy");    // add by zdn 2001-07-13

	add_door("������", "������", "����������լ");
	CBox * box = Add_Box();
	box->add_object("pixie_sword_book", 1);	
	box->set_name( "ľ��");
	set("long", "�����Ǹ����ھ�����ͷ�������ڸ����ľɾӡ����ڵļҾߺ������˵ص��ڵ��ϡ������һ�ǽ���һ��֩���������ﵽ���ǳ�������Ȼ���Ѿ��ܾ�û����ס�ˡ�����ľ�ͷ��һ����(men)�����ѱ�̮����ש�ߵ�ס�ˡ�" );
	
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
