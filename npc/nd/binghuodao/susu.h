// yinsusu.h  ����
// 2001-07-18    zhangdongni

NPC_BEGIN(CNbinghuodao_susu);

virtual void create()
{
        set_name("ӣ����", "yin susu");
        set("nickname", "susu");
        set("gender", "Ů��");
        set("long","����һλ���������Ḿ�ˣ���һ���÷���");
                                                          
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("icon", young_woman2);

        set("age", 27);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("hp", 3500);
        set("max_hp", 3500);
        set("mp", 3000);
        set("max_mp", 3000);
        set("combat_exp", 900000);
        set("mp_factor", 1000000);

        set_skill("force", 180);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("claw", 200);
        set_skill("literate", 100);
        set_skill("jiuyang_shengong", 180);
        set_skill("xiaoyaoyou", 120);
        set_skill("longzhua_gong", 250);
        
        set_inquiry("��ëʨ��", "���м����Ҵ�磿����Ҳ��֪��磬�����ڿɰ��ã�");
        set_inquiry("�Ŵ���", "���˵������Զ����һ�𣬾����ֿ��ģ�");
        set_inquiry("�޼�","�޼ɻ�С���治֪���Ժ��·��������!");


        map_skill("force", "jiuyang_shengong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("claw", "longzhua_gong");
        map_skill("parry", "longzhua_gong");
        prepare_skill("claw","longzhua_gong");

        set("chat_chance", 1);
        
//        carry_object("bluecloth")->wear();	
}


virtual char * chat_msg()				
{
		return "������̾��һ������������֪��������һ�����Ķ���̫�࣬����ɱ����Ҳ��������...��";
}  
     

 //       set("chat_chance_combat", 10);  


       


NPC_END;