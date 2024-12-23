//pub_liqiuhen.h
//wuqing 2002-2-10

NPC_BEGIN(CNpub_liqiuhen);

virtual void create()
{    
    set_name("�����", "li qiou hen");
    set("long","���������ǽ����ϵ���Ů��������Ϊ�껪��ȥ�������˲�����������");	
    set("gender", "Ů��"); 
    set("title","�̲�����");
    set("age", 75);
    set("str", 40); 
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("per", 40);
    set("icon",young_woman4);

    set("max_hp", 25500);
    set("mp", 18000);
    set("max_mp", 18000);
    set("mp_factor", 400); 
    set("combat_exp", 7000000); 
    set("score", 200000);

    set_skill("force", 350);
    set_skill("beiming_shengong", 350);
    set_skill("dodge", 350);
    set_skill("lingboweibu", 350);
    set_skill("unarmed", 350);
    set_skill("liuyang_zhang", 350);
    set_skill("parry", 350);
    set_skill("blade", 350);
    set_skill("xiaoyao_dao", 350);
    set_skill("zhemei_shou", 350);
    set_skill("hand", 350);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 380);
    set("apply/damage", 200);
    carry_object("gangdao")->wield();

}

virtual void die()
{
	CContainer * obj = environment();
	char msg[255];
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(is_fighting(target)==1 && EQUALSTR(target->querystr_temp("gumu/kill_name"), "�����")&& EQUALSTR(target->querystr_temp("gumu/kill_id"), "li qiou hen"))
		{
			message_vision("\n$N��Ȼ�������ȥ���߰���������Ȼ��$N�������ˣ��ӽ��Ժ��Ҳ��ٹ���������Щ�����ˣ���ң���˳���������������", this);
			target->delete_temp("gumu/kill_name");
			target->delete_temp("gumu/kill_id");
			target->add("combat_exp",target->query_temp("gumu/kill_exp"));
			message_vision(snprintf(msg, 255, "$HIR$N�����%d�������齱����\n",target->query_temp("gumu/kill_exp")), target);
			target->delete_temp("gumu/kill_exp");
			target->add_temp("gumu/jq_renwu",1);
			continue;
		}
	}
	CNpc::die();
}
NPC_END;

 



