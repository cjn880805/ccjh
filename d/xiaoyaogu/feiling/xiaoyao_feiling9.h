//xiaoyao_feiling9.h ����֮������
//�ز� 2003��3��15

XiaoYao_BEGIN(CRXiaoYao_feiling9);

virtual void create()
{
	set_name( "����֮������");
	set("no_autosave",1);
	set("index",9);

	add_item("shicheng");

	add_door("����֮�ұ���", "��ң�ȷ���֮�ұ���", "��ң�ȷ���֮������");
	add_door("����֮��", "��ң�ȷ���֮��", "��ң�ȷ���֮������");

};

XiaoYao_END;
