//road1.h

//Sample for room: ���������
//coded by Fisho
//data: 2000-11-3

CHANGAN_BEGIN(CRChangAn_road1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	add_npc("pub_jianke");    //2001-07-12 zdn add

	add_door("�������Ŵ��", "�������Ŵ��", "���������");
	add_door("�������ȹ�", "�������ȹ�", "���������");

	set("long", "����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮�������ݣ�������ֱ�ﳤ���ǡ�" );
	

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

CHANGAN_END;
