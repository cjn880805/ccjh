//GaoCang_mg_9.h ������5��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_9);

virtual void create()			
{
	set_name("�������");

	CDoor * a = add_yewaidoor("west", 10, 20);
	CDoor * b = add_yewaidoor("north", 10, 20);
	CDoor * c = add_yewaidoor("east", 10, 20);
	CDoor * d = add_yewaidoor("south", 10, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��ʺ����", "�߲���ʺ����", "�߲��������");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("�η���һ����ִ���ͳ�������������ߣ�����������������̶ȥ���̡�����һ��ɲ�ľ޴����̶��ʢ����ɫ��ˮ��������������̶���������Ҳ�̶�߶�������һ�������������̶֮�С� ", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
