//GaoCang_mg_19.h ������15��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_19);

virtual void create()			
{
	set_name("������");

	CDoor * a = add_yewaidoor("west", 20, 20);
	CDoor * b = add_yewaidoor("north", 20, 20);
	CDoor * c = add_yewaidoor("east", 20, 20);
	CDoor * d = add_yewaidoor("south", 20, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��ĥ����", "�߲���ĥ����", "�߲�������");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("�����в�������ʯ��ֻ��һ�����ڵ�����ͷ��¶�⣬˫�ֺ�ʮ������������ǩ���̱��յ�����ֱ�С�������һ˫ͷ����������������ָ�Ӷ������̡�", me);
	say("һ������һ������������������ѹס��һ�������������ݺݴ������壬���һ���˱��廨�����ʯ���ϣ���һ���������������ʬ��", me);
	say("���һʯ�ұߣ�һ������ſ�ڵ��ϣ��������������������������ǰһ�����������ó��������а������ʩ�Լ��̣���һ��������ɱ������������ϵ����������ڹ��������桢����ʩ�Կ��̡�", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
