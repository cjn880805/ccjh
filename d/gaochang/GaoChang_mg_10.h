//GaoCang_mg_10.h ������6��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_10);

virtual void create()			
{
	set_name("�𺣵���");

	CDoor * a = add_yewaidoor("west", 11, 20);
	CDoor * b = add_yewaidoor("north", 11, 20);
	CDoor * c = add_yewaidoor("east", 11, 20);
	CDoor * d = add_yewaidoor("south", 11, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("�������", "�߲��������", "�߲��𺣵���");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("�Ҽ䣬һ�޴�������͹����ڳ���ƽ̨�ϣ����й��ͷ��ڣ���ͷ����֫�ڹ��з�����һ���ֹ��ڹ��н�������������ǿ������һ������Ͷ����У�������ø�̧�������ߣ���ʯ�ݽ��������͹����͹�ƽ̨�ϣ��д���ľ�����������ε���ǽ�ߣ��о��ŵû겻����������߹�����ġ�", me);
	say("�����е��ջ���æµ���ڹ��߹ķ�߻�Զ��������ʬ��ϡ�ɼ�������й�С����ʩ�̣�����ʽ�طֲ����γ�͸�ӣ������еĴ��ģ�����������ڣ��������Ц���������ߵĲҽ������һ�飬�����ǵ���Ц�·��ڳ�����Щ�����������ˣ������ܵظ��в�˼��ĵ����ˡ�", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
