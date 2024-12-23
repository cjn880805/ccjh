// yinsusu.h  素素
// 2001-07-18    zhangdongni

NPC_BEGIN(CNbinghuodao_susu);

virtual void create()
{
        set_name("樱素素", "yin susu");
        set("nickname", "susu");
        set("gender", "女性");
        set("long","他是一位身材窈窕的年轻妇人，身穿一件裘服。");
                                                          
        set("gender", "女性");
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
        
        set_inquiry("金毛狮王", "你有见到我大哥？唉，也不知大哥，他现在可安好？");
        set_inquiry("张翠三", "五哥说我们永远会在一起，绝不分开的！");
        set_inquiry("无忌","无忌还小，真不知他以后的路会是怎样!");


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
		return "殷素素叹了一口气道：“我知道，我这一生做的恶事太多，胡乱杀的人也不计其数...”";
}  
     

 //       set("chat_chance_combat", 10);  


       


NPC_END;