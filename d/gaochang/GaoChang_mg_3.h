//GaoCang_mg_3.h ������ڶ��κ���
//�ز� 2004.12.27

YEWAIDOOR_BEGIN(CRGaoChang_mg_3);

virtual void create()			
{
	set_name("�κ���");

	CDoor * a = add_yewaidoor("west", 4, 20);
	CDoor * b = add_yewaidoor("north", 4, 20);
	CDoor * c = add_yewaidoor("east", 4, 20);
	CDoor * d = add_yewaidoor("south", 4, 20);

	a->set_name("�Թ���");
	b->set_name("�Թ���");
	c->set_name("�Թ���");
	d->set_name("�Թ���");
	add_door("��Ȫ֮·", "�߲���Ȫ֮·", "�߲��κ���");
	add_npc("dy_master");

	set("long", "������ͨ��ʮ�˵����ġ��κ��š����������е�ʯ���ţ�������ƽ�أ���С��������ȫ��ͬ��ÿ�ſ���ĳ������໤�Ե�ʯ���������Գʻ��Σ�����ʯ���������˸�������̤�������¿�һ���γأ��ص׼��űھ�Ϊ��ʯǶ��������Ѫ����������������η������ȷ����档");

};

YEWAIDOOR_END;
