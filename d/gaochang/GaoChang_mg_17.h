//GaoCang_mg_17.h ������13��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_17);

virtual void create()			
{
	set_name("��������");

	CDoor * a = add_yewaidoor("west", 18, 20);
	CDoor * b = add_yewaidoor("north", 18, 20);
	CDoor * c = add_yewaidoor("east", 18, 20);
	CDoor * d = add_yewaidoor("south", 18, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("���Ե���", "�߲����Ե���", "�߲���������");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("���й�ʯ���������ŭ�š�ʯ����ʯ����խ�밵��͸��϶������������Χ�Ǹ�ͤ����ʯ����ʱ�����ͷħצ��", me);
	say("�Ҳ�һ��ʨŭ���ŴӰ������һ�������˹�ȥ�����˱��ŵþ�����״����һ�����ŵñ�ͷ�󴮣���ͷ����β������һ�����ŵ��ε��ڵأ����һ�ͻ����ͻ���ɽ֮�ƴ�ɽ����һŮ��������������Ů���˵����ε�����������Ҳ�ŵû����ɢ��", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
