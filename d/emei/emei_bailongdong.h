ROOM_BEGIN(CREMei_bailongdong);

virtual void create()			
{
	set_name( "���Ұ�����");

	CBox * box = Add_Box();

	box->add_object("coin", 60000);	//put 100 coind into box

	box->set_name( "����֮ӡ", "enchantment");
	box->Locked("���", 9000);
	
	add_npc("pub_daoke");    // add by zdn 2001-07-13

	add_door("����������", "����������", "���Ұ�����");
	add_door("����������", "����������", "���Ұ�����");

	set("long","��������˵�ǡ����ߴ����еİ�������������֮���������ľ���죬����е���������ͦ���Σ�֦Ҷ����������������ӵ�𣬴�Ϊ��ʱһ��ɮ����������������һ�֣�ֲ��һ�꣬��ֲ�����ǧ�߰���ʮ���꣬ʱ�ƹŵ��֡����ﱱ���������֣�������������(shibei)���ɴ������ϣ������Ǻ�����ջ������·������������ȥ�з��¡�");

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
