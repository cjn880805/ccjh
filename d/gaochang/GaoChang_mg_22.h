//GaoCang_mg_22.h ������18��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_22);

virtual void create()			
{
	set_name("���ǵ���");

	CDoor * a = add_yewaidoor("west", 23, 20);
	CDoor * b = add_yewaidoor("north", 23, 20);
	CDoor * c = add_yewaidoor("east", 23, 20);
	CDoor * d = add_yewaidoor("south", 23, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��ͭ����", "�߲���ͭ����", "�߲����ǵ���");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("������ͬ��״�����š���������ǽ����ͤ��¶��Զ�����Ҳ��У�������������ʯ�����϶��£�ʯ�������Ź���վ�ں��������������ڿ�����", me);
	say("���������ͺ���Ÿ��ִ�С���������������ܲ�������һ���ͽ����������룬ֱ���������������˱����ڽ����£�һ�����ſ�Ѫ����ҧ�����˲��ھ����ϣ����۲�ͣ���������˵Ķ���", me);
	say("�����ɳ�����������˱����俴Ѻ�����ڲ�ͣ�ر�ɳ���Աߣ�����������׷�Ϻͱ޴��ﷸ��ǿ���ﷸ����ϵ��ܿࡣ", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
