//GaoCang_mg_14.h ������10��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_14);

virtual void create()			
{
	set_name("��������");

	CDoor * a = add_yewaidoor("west", 15, 20);
	CDoor * b = add_yewaidoor("north", 15, 20);
	CDoor * c = add_yewaidoor("east", 15, 20);
	CDoor * d = add_yewaidoor("south", 15, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��ɽ����", "�߲���ɽ����", "�߲���������");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("���У���ɽѩ�أ������Х��Զ���ص���Χ�ǻ�����������ѩ�������ε�Χ�Ǵ����������ѩ���ͺ��磬��״����ı����ϣ��������������������ò�����", me);
	say("�Ժ󣬱�����ı�ɽ���������������ѩ��֮�У��еĳ������壬�е�ֻ�����ã���������ֱ����£����ǡ�·�ж����ǣ�����ʬ�Ǻ���������ǳֵ��ٰ����䱸ɭ�ϣ�Ψ�б�ɽ��������΢����˸�� ", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
