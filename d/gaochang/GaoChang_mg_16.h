//GaoCang_mg_16.h ������12��
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_16);

virtual void create()			
{
	set_name("���Ե���");

	CDoor * a = add_yewaidoor("west", 17, 20);
	CDoor * b = add_yewaidoor("north", 17, 20);
	CDoor * c = add_yewaidoor("east", 17, 20);
	CDoor * d = add_yewaidoor("south", 17, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��Ƥ����", "�߲���Ƥ����", "�߲����Ե���");
	add_npc("dy_master");

};

virtual int do_look(CChar * me)
{
	say("����ǰһ�޹�����һ���ˣ���һ��ʯ�Ͻ������ӽ����У����ܸ�ǽ��������ǽ����ľ׮���ɵ���Ȧ��Ȧ�У�ţ�����������ǡ���������ʨ�ȶ�������˺ҧ��ʳ���ˣ���֫�����ȡ���ͷ���Ѷǣ�����ʹ���쳣��", me);
	SendMenu(me);
	return 1;
}

YEWAIDOOR_END;
