//GaoCang_mg_13.h ������9��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_13);

virtual void create()			
{
	set_name("��ɽ����");

	CDoor * a = add_yewaidoor("west", 14, 20);
	CDoor * b = add_yewaidoor("north", 14, 20);
	CDoor * c = add_yewaidoor("east", 14, 20);
	CDoor * d = add_yewaidoor("south", 14, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��������", "�߲���������", "�߲���ɽ����");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("Զ����ɽ�ص�������˷���ɽ�½�Ϫ������Զ����ǡ�������޵���Ԩ��Զ�н��ֲ�һ���վ����ص�ɽ�ۣ�ɽ��֮�������������������Ǳ����Ѻ�š������ű��������ʵǣ�ǿ�ƹ�������", me);
	say("�е�������ɽ���е�����ɽ��������Ƶ�ɽ�£��еĹ�������������Ԩ����������ɽ��������Է�վ���޹��ұߵĳֲ棬��ߵĳ�������ŭ���Ź������������Ƿ׷׵���Ϫ�������ǰ����ɽ�������� ", me);
	SendMenu(me);
	return 1;
}
YEWAIDOOR_END;
