//xiaoyao_baihu31.h �׻�������
//�ز� 2002��12��17

XiaoYao_BEGIN(CRXiaoYao_baihu31);

virtual void create()
{
	set_name( "�׻�������");
	
	add_door("�׻�������", "��ң�Ȱ׻�������26", "��ң�Ȱ׻�������31");
	
	add_door("�׻�������2", "��ң�Ȱ׻�������32", "��ң�Ȱ׻�������31");
	
	add_npc("xy_baihu3");
	add_npc("xy_baihu3");

	set("����",random(4)+4);
	set("λ��",random(2)+1);
	set("����","�׻�");
	
};

int valid_leave(CChar * me, const char * dir)
{
	if(userp(me))
	{
		if(!me->query("xy/renwu4_3"))
		{
			me->move(load_room("��ɽ������"));
			return 0;
		}
		else if(!me->query_temp("xy/renwu4_1"))
		{
			tell_object(me, "\n$HIRͨ������һƬ�����滹��ʱ����һЩ�����������ֻ�ŵ����ľ������������ٽ�ǰһ�����������ǵ���ʦ������ʦ���������Ϊ��׳׳����\n");
			me->move(load_room("��ң�ȿյ�"));
			return 0;
		}
		CContainer * ShouWei=present("zhu zhuangshi");
		if(ShouWei)
		{
			tell_object(me, "$HIR�׻�������ȵ������󵨿�ͽ�������Ҵ��׻���������������������£���");
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}
XiaoYao_END;
