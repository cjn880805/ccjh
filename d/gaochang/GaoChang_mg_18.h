//GaoCang_mg_18.h ������14��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_18);

virtual void create()			
{
	set_name("��ĥ����");

	CDoor * a = add_yewaidoor("west", 19, 20);
	CDoor * b = add_yewaidoor("north", 19, 20);
	CDoor * c = add_yewaidoor("east", 19, 20);
	CDoor * d = add_yewaidoor("south", 19, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��������", "�߲���������", "�߲���ĥ����");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("���м����ϵ���ʯ���ι�״�������ұ�����������С����խ��һ��������֬�͵���Զ������", me);
	say("���У��޴���ĥ���˸����̸Ц��������շ�ţ���ĥ�������������������˷ֱ����ĥ�ģ���շ�����⽬��ĥ����������̰����СҰ����ʳ��ĥ��ð����Ѫ����һҰ��������ĥ̽ʳ��ת��", me);
	say("Զ�������϶���������ħ��һ�������ϰ�������ĥ�ģ�ֻ���������⡣���������õ�˽�������֫����һ�������ĥĥ�ġ�", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
