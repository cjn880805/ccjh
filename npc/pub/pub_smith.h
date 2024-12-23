// pub_smith.c

// code by Fisho
// date:2000-12-17
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_smith);

virtual void create()
{
	set_name("������", "feng");

	set("icon", smith_boss);
	set("gender", "����" );
	set("age", 53);
	set("long","���������ǳ��������������������ˣ�˫�۱��̻�޹���ֺ���ϸ�����Ȳзϣ������³���һ�����ȡ�");
	set("combat_exp", 50000);
	
	set("str", 24);
	set("dex", 17);
	set("con", 28);
	set("int", 27);
	set("shen_type", 1);
	
	set("attitude", "friendly");
	set_skill("dodge", 70);
	set_skill("hammer", 40);
	set_skill("parry", 60);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	carry_good("hammer",500);

 	set_inquiry("name","С���շ룬�����˶����ҷ�������");
 	set_inquiry("here","������С�˺��ڵ����ӣ�С�˾�ס����ߵ����ӡ�");
 	set_inquiry("��ͷ","��ͷ... ��Ǹ����ͷ�Ѿ�������...");
 	set_inquiry("����","������С������������������ã�һ��ֻҪ������Ǯ��");
 	set_inquiry("��","Ŷ�����Ǹ���ɽ�������Ŵ�ģ�С�����������£�����û�˷��ǿ�������ţ�������ǰ��������ͽ��ɽȥ�ˣ���֪ʲ��ʱ��Ż�������ȡ����");
 	set_inquiry("ȡ��","С��һ��Ҫ���������ŵ����Ų��ܸ�����");
 	set_inquiry("��Ĭ��","������������ֺ������ı�С˵�￴��...");
 	set_inquiry("���Ŷݼ�","�Ƕ���Сʱ��ѧ�ģ�ƽʱû�½���ư��ˡ�");

	add_money(50);
	carry_object("hothammer")->wield();
	set("no_huan",1);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( EQUALSTR(ob->querystr("base_name"), "letter"))
	{
		if(!query("yl_trigger")) 
		{
			say("��ѽ��䲻���ۣ���Ҳ��С�˵���Ѫ������Ե��������š�", who);
			load_item("youlongsword")->move(who);
			set("yl_trigger", 1);
		}
		else 
			say("Ҫ���Լ���ȥ�á�", who);

		destruct(ob);
//      call_out(destroy, 1, ob);
		SendMenu(who);
		return 1;
	}

	return 0;
}
/*
void destroy(CContainer * ob)
{
	destruct(ob);
	return;
}
*/
VENDOR_END;