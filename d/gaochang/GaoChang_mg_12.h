//GaoCang_mg_12.h ������8��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_12);

virtual void create()			
{
	set_name("��������");

	CDoor * a = add_yewaidoor("west", 13, 20);
	CDoor * b = add_yewaidoor("north", 13, 20);
	CDoor * c = add_yewaidoor("east", 13, 20);
	CDoor * d = add_yewaidoor("south", 13, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��������", "�߲���������", "�߲���������");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("�Ҳ�����Χ�ǣ�Χ������ʯ����ʯ����ľ����ʯ����ľ�ʴ������ܡ�������ľ���ȡ�����ʯ������һ�޵�����������ͷ�����͸��񣬹��̵��������������ս��������ˡ�", me);
	say("����Ǿ��������������ˣ��е�����������������̣������߶��������������������ȼ�ϣ�����������ǿ��Ѻ�������ߵ�����������������һ�ߴ���Ӳ�����ɡ�", me);
	SendMenu(me);
	return 1;
}
YEWAIDOOR_END;
