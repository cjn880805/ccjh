//GaoCang_mg_8.h ������4��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_8);

virtual void create()			
{
	set_name("��ʺ����");

	CDoor * a = add_yewaidoor("west", 9, 20);
	CDoor * b = add_yewaidoor("north", 9, 20);
	CDoor * c = add_yewaidoor("east", 9, 20);
	CDoor * d = add_yewaidoor("south", 9, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��ɳ����", "�߲���ɳ����", "�߲���ʺ����");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("�γ�ת�ǵ�Χ�Ǹ�ǽ���и������м��ǽ��һ�����ڷ��̹���������������ԣ��ֳֳ���ư���������յù��̵��۽��Ӹ�ǽ����к��ǽ�µ����������ϡ���", me);
	say("���������������ڱ�ľ�ݡ�������Χ��ƽ̨�ϣ���������������ſ��ľ׮�ϣ����ö������Ҳ�߸ߵ�ʯ���ϣ�������Ѻ�������ߵ���ʺ�������̡�", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
