//GaoCang_mg_21.h ������17��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_21);

virtual void create()			
{
	set_name("��ͭ����");

	CDoor * a = add_yewaidoor("west", 22, 20);
	CDoor * b = add_yewaidoor("north", 22, 20);
	CDoor * c = add_yewaidoor("east", 22, 20);
	CDoor * d = add_yewaidoor("south", 22, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("�������", "�߲��������", "�߲���ͭ����");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("�����в�����ʯ��һ���ž޴�Ŀ���ͭ���������ϣ��һ����ܣ���һ����ͭ���յ�ͨ�졣��ǰ�棬�޴��ͭ���������ĸ������ߣ���������֮�ࣻԶ�������Ŵ�Сͭ�����������һ�����ˣ����������ˡ�", me);
	say("�����ʯ�ϵ���������������ߣ������ͭ���ԣ�һ�����������ס���̵�����ʹ�䲻�ܶ�������һ����ֳֿ����������ɷ��������ŭ��������������½ǼӲ���Ȼ��æ����ͣ��", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
