/**
* Engenharia de Software Moderna - Testes  (Cap. 8)
* Prof. Marco Tulio Valente
* 
* Exercício simples de teste de unidade (ShoppingCart)
*
*/

import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import java.util.ArrayList;
import java.util.List;

public class TesteShoppingCart {

  private ShoppingCart shoppingCart;
  private Item itemESM;
  private Item itemGoF;

  @Before
  public void setUp() {
    shoppingCart = new ShoppingCart();
    
    itemESM = new Item("ESM", 65.0);
    itemGoF = new Item("GoF", 120.0);

    shoppingCart.addItem(itemESM);
    shoppingCart.addItem(itemGoF);
  }

  @Test
  public void testAddItem() {
    Item itemTeste1 = new Item("Teste1", 777.0);
    Item itemTeste2 = new Item("Teste2", 888.0);
    Item itemTeste3 = new Item("Teste3", 999.0);

    shoppingCart.addItem(itemTeste1);
    shoppingCart.addItem(itemTeste2);
    shoppingCart.addItem(itemTeste3);

    assertEquals(5, shoppingCart.getItemCount());
  }

  @Test
  public void testRemoveItem() {
    shoppingCart.removeItem(itemESM);

    assertEquals(1, shoppingCart.getItemCount());
  }

  @Test
  public void testGetTotalPrice() {
    double totalPrice = itemESM.getPrice() + itemGoF.getPrice();
    assertEquals(totalPrice, shoppingCart.getTotalPrice(), 0.0);
  }

  @Test
  public void testClearCart() {
    shoppingCart.clearCart();
    assertEquals(0, shoppingCart.getItemCount());
  }
}
