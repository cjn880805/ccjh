NPC_BEGIN(CNpub_hehongyao);

virtual void create()
{
	set_name("�κ���","hehongyao");
	
	set("icon", young_woman8);
	set("gender", "Ů��" );
	set("age", 47);
	set("long", "��Ů�˾���������ţ���ͷ���棬ͷ���ҵ����ѣ�ʮָ���缦צ������������ֵ��˺ۣ������Ǳ�����˺ҧ���£��˺���ڲ�����Ŀ��");
	set_temp("apply/defense", 5);
	set("combat_exp", 70000);
	set("shen_type", -1);
	set("per", 12);
	set("str", 34);
	set("dex", 35);
	set("con", 36);
	set("int", 35);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	set("attitude", "friendly");	
};

NPC_END;
