//GaoCang_mg_20.h ������16��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_20);

virtual void create()			
{
	set_name("�������");

	CDoor * a = add_yewaidoor("west", 21, 20);
	CDoor * b = add_yewaidoor("north", 21, 20);
	CDoor * c = add_yewaidoor("east", 21, 20);
	CDoor * d = add_yewaidoor("south", 21, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("������", "�߲�������", "�߲��������");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("����һ�޴����ʯ�м���һԲ����ӣ�����ڣ�һ�����С���߲��������������ߡ���Ы���������ҧ��ʳ������߸ߵ���ʯ�ߣ�һ������������Ѻ����������С�", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
